# python_cpp
Exemple d'utilisation d'un composant en python
Utilise pybind11
apres git clone, faire:
```
cd python_cpp
git submodule init
git submodule update
```

Pour compiler

```
cd hello
make
```

Pour utiliser
```
python3
>>> import hello_component
>>> hello_component.greet()
'hello, world'
>>> hello_component.getVersion()
'1.1'
>>> 
```
## Exemple utilisation d'un objet C++ : Une voiture
```
python3
>>> from hello_component import Voiture
>>> toyota = Voiture('yaris', 5)
>>> toyota.get_nom()
'yaris'
>>> toyota.get_litreEssence()
'5'
>>> toyota.rouler()
>>> toyota.get_litreEssence()
'4'
>>> toyota.setEssence(10)
>>> toyota.get_litreEssence()
'10'
>>>
```