#include <gePrerequisitesUtil.h>
#include <geVector2I.h>


using geEngineSDK::Vector2I;

class RTSTiledMap;
// cambiarlo a clases, totalmente n herencia
/*
  NONE = -1,
  BreadthFirstSearch,
  DepthFirstSearch,
  BEST,
  DIJKSTRA,
  ASTAR
  /**/


// una vez revisa hace el camino
// Una herramienta que se va usar en el mapa, sin modificar el mapa 

struct PathNode
{
  PathNode()
  {
    position = Vector2I(0, 0);

    isExplored = false;

    isNodesExplored = false;
  }

  PathNode(Vector2I _position, bool _isExplored = false, bool _isNodesExplored = false)
  {
    position = _position;

    isExplored = _isExplored;

    isNodesExplored = _isNodesExplored;
  }

  ~PathNode() = default;

  Vector2I position;

  bool isExplored;

  bool isNodesExplored;
};

class PathFinder
{
public:
  PathFinder();
  ~PathFinder() = default;

  void
  update();

  void
  run(const Vector2I& start, const Vector2I& target, const Vector2I, RTSTiledMap* tiledMap);

  bool
  step(PathNode node, RTSTiledMap* tiledMap);

private:
  geEngineSDK::Vector<PathNode> connections;

  geEngineSDK::Vector<PathNode> currentNodes;

  PathNode targetNode;

  uint16 nextNodeID;



};





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
