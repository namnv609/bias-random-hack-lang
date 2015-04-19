<?hh // strict

require_once 'BiasRandom.hh';

$biasRandom = new wataridori\BiasRandom\BiasRandom();

$data = [
    'HipHop Virtual Machine' => 10
];

$biasRandom->setData($data);
$biasRandom->addElement('HipHop', 20);
$biasRandom->addElement('Virtual', 30);
$biasRandom->addElement('Machine', 40);
$biasRandom->addElement('Framgia', 50);
$biasRandom->addElement('Viblo', 5);

print_r($biasRandom->random());