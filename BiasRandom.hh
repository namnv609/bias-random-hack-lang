<?hh // strict

namespace wataridori\BiasRandom;

class BiasRandom
{
    protected array<mixed, int> $data = [];

    public function __construct(array<mixed, int> $data = []): void
    {
        $this->data = $data;
    }

    public function addElement(mixed $name, int $weight): bool
    {
        if (is_string($name) || is_numeric($weight)) {
            $this->data[$name] = $weight;

            return true;
        }

        return false;
    }

    public function removeElement(mixed $name): void
    {
        unset($this->data[$name]);
    }

    public function setData(array<mixed, int> $data): void
    {
        $this->data = $data;
    }

    public function getData(): array<mixed, int>
    {
        return $this->data;
    }

    public function getRandom(array<mixed, int> $data): mixed
    {
        $total = 0;
        $distribution = [];

        foreach ($data as $name => $weight) {
            $total += $weight;
            $distribution[$name] = $total;
        }

        $rand = mt_rand(0, $total - 1);

        foreach ($distribution as $name => $weight) {
            if ($rand < $weight) {
                return $name;
            }
        }
    }

    public function random(int $count = 1): array<mixed, int>
    {
        $data = $this->data;
        $result = [];

        for ($i = 0; $i < $count; $i++) {
            if (!$data) {
                break;
            }

            $name = $this->getRandom($data);
            $result[] = $name;
            unset($data[$name]);
        }

        return $result;
    }
}