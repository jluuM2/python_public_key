#include <pybind11/pybind11.h>

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