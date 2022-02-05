#include "PathFinder.h"

#include "RTSTiledMap.h"


PathFinder::PathFinder()
{
  targetNode = PathNode();

  nextNodeID = 0;

  connections = {
  PathNode({ 1, 0}), // Right
  PathNode({ 1, 1}), // Top Right
  PathNode({ 0, 1}), // Top
  PathNode({-1, 1}), // Top Left
  PathNode({-1, 1}), // Left
  PathNode({-1,-1}), // Butt Left
  PathNode({ 0,-1}), // Butt
  PathNode({ 1,-1}), // Butt Right
  };
}

void PathFinder::update()
{

}

void PathFinder::run(const Vector2I& start, const Vector2I& target, const Vector2I, RTSTiledMap* tiledMap)
{
  bool isSearchingPath = false;

  // verificar que los datos recividos sean correctos
  if (isSearchingPath == false)
  {
    bool isStartSize = ((start.x >= 0) && (start.x < tiledMap->getMapSize().x) && (start.y >= 0) && (start.y < tiledMap->getMapSize().y));

    bool isTargetSize = ((target.x >= 0) && (target.x < tiledMap->getMapSize().x) && (start.y >= 0) && (target.y < tiledMap->getMapSize().y));
  
    if (tiledMap == nullptr || isStartSize == false || isTargetSize == false || start == target) {
      return;
    }
  
    isSearchingPath = true;

    targetNode.position = target;

    currentNodes.push_back(PathNode(start, true));
  
  }
  else
  {
    // Explorar a partir de un nodo, hasta encontrar el nodo que buscamos
    while (isSearchingPath == false)
    {
      isSearchingPath = step(currentNodes[nextNodeID], tiledMap);
    }


  }
}

bool PathFinder::step(PathNode node, RTSTiledMap* tiledMap)
{
  // explorar los nodos 
  for (uint8 i = 0; i < connections.size(); i++)
  {

    PathNode nextNode = PathNode(node + connections[i].position, false);

    if (((nextNode.position.x >= 0) && (nextNode.position.x < tiledMap->getMapSize().x) &&
         (nextNode.position.position.y >= 0) && (nextNode.position.y < tiledMap->getMapSize().y)) &&
         (tiledMap->getType(nextNode.position.x, nextNode.position.y) != TERRAIN_TYPE::E::kObstacle))
    {
       // checar que sea el nodo que buscamos
       if (tiledMap == targetNode.position)
       {

         nextNode.isExplored = true;

          currentNodes.push_back(nextNode);

          return true;
       }

       // guardar los nodos si no han sido explorados

       if (nextNode.isExplored == false)
       {

         nextNode.isExplored = true;

         currentNodes.push_back(nextNode);
       }

    }
  }

  node.isNodesExplored = true;

  
  for (uint16  = 0, i < currentNodes.size(), i++)
  {
    // escoger el siguiente nodo
    if (currentNodes[i].isNodesExplored == false)
    {
      nextNodeID = i;

      return false;
    }
  }

  // return false; 
}

// explorar los nodos
// checar que sea el nodo que buscamos
// guardar los nodos 
// escoger el siguiente nodo (esto es lo que cambia)


// *Crear una lista por los cuales fui avanzando?*