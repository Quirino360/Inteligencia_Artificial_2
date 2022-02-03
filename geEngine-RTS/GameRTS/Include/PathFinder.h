
#include <gePrerequisitesUtil.h>
#include <geVector2I.h>


using geEngineSDK::Vector2I;

class RTSTiledMap;
class PFNode;

// cambiarlo a clases, totalmente n herencia
enum class SEARCHING_TYPE {
	NONE = -1,
	BF,
	DF,
	BEST,
	DIJKSTRA,
	ASTAR
};


// una vez revisa hace el camino
// Una herramienta que se va usar en el mapa, sin modificar el mapa 
class PathFinder
{
public:
	PathFinder();
	~PathFinder() = default;

private:

public:


	void
	update();

	
	void
	run(const Vector2I& start, const Vector2I& target, const Vector2I, RTSTiledMap* _tiledMap, const SEARCHING_TYPE _searchTypeID = SEARCHING_TYPE::NONE);

	
	bool
	step(RTSTiledMap* _tiledMap, const SEARCHING_TYPE _searchTypeID);



private:

	bool isSearchingPath;

	// current node it is searching
	PFNode currentNode;
	PFNode targetNode;

	// next nodes it will check
	std::vector<PathNode> nextNodes;
	geEngineSDK::Vector<PathNode*> currentNodes;

	void
	BreadthFirstSearch(RTSTiledMap* _tiledMap);

};

// Camel o pascal
// Los nodos se van creando segun se vean las posibilidades
class PathNode
{
public:
	PathNode() = default;

	PathNode(Vector2I _pos) : {
		position = _pos;
	};

	~PathNode() = default;
private:
	Vector2I position;

	// Connections
	geEngineSDK::Vector<PathNode*> connections;

public:
	void setNodes(Vector2I mapSize);
	void nextNode() {
		
	}
};


//Cual paso va siguiente

//Cada vez que se haga una revixion  
// step y run 

// Porque craer una clase dentro de una clase? (RTSTiledMap)
// Que es la clase UnitType (UnitType)
// No entiendo la funcion que usa con suus enum de set y get (RTSTiledMap)


	//5 PathFinders
	// Escoger entre los 5 algoritmos en una UI
	// Poder setear pesos, con el ejemplo que vimos
	// Interfaz de control
	//_tiledMap->getType
