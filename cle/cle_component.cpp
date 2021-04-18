#include <pybind11/pybind11.h>
#include "micro-ecc/uECC.h"
char version[]="1.0";

char const* getVersion() {
	return version;
}

class Cle
{
    public:
        Cle(){}
        ~Cle() {}

        void initialize(std::string &nb) { 
		PrivateKey=nb;
		const uint8_t* castIntPrivateKey=reinterpret_cast<const uint8_t*>(PrivateKey.c_str());
		const int publicKeySize=uECC_curve_public_key_size(uECC_secp256k1());
		uint8_t *varIntPublicKey = new uint8_t(publicKeySize);
		uECC_compute_public_key(castIntPrivateKey,varIntPublicKey,uECC_secp256k1());
		PublicKey=std::string( varIntPublicKey, varIntPublicKey+publicKeySize );
		}
		
        const std::string &getPrivateKey() const { return PrivateKey; }
		const std::string &getPublicKey() const { return PublicKey; }

    private:
        std::string PublicKey;
        std::string PrivateKey;
};
 
namespace py = pybind11;


PYBIND11_MODULE(cle_component,greetings)
{
  greetings.doc() = "greeting_object 1.0";
  greetings.def("getVersion", &getVersion, "a function returning the version");
  
   // bindings to Cle class
    py::class_<Cle>(greetings, "Cle", py::dynamic_attr())
        .def(py::init())
        .def("initialize", &Cle::initialize)
        .def("getPrivateKey", &Cle::getPrivateKey)
        .def("getPublicKey", &Cle::getPublicKey);
}