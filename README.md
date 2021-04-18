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
'1.0'
>>> 
```
## Exemple utilisation d'un objet C++ : Une voiture
J'ai crée un nouveau composant nommé voiture_composant.
```
python3.7
>>>	import voiture_component
>>>	voiture_component.getVersion()
'1.0'
>>> from voiture_component import Voiture
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
![Image voiture](/images/voiture.png)

## Création d'une clé en utilisant la courbe secp256k1
Pour récupérer le clé public à partir de la clé privée, j'ai utilisé la librairie [micro-ecc](https://github.com/jluuM2/micro-ecc). 
J'ai ensuite include le uECC.h. Le code du projet marche semble marcher correctement sur un IDE (Clion)car les dépendances vers micro-ecc sont bien chargés mais ne fonctionne pas autrement.
J'ai crée un nouveau composant nommé cle_component
```
python3.7
>>>	import cle_component
>>> cle_component.getVersion()
'1.0'
>>> from cle_component import Cle
>>> c1=Cle()
>>> c1.initialize("4b8e29b9b0dddd58a709edba7d6df6c07ebdaf5653e325114bc5318c238f87f0")
>>> c1.getPrivateKey()
'4b8e29b9b0dddd58a709edba7d6df6c07ebdaf5653e325114bc5318c238f87f0'
>>> c1.getPublicKey()

