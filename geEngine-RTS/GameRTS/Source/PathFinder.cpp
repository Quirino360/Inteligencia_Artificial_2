#include "PathFinder.h"

#include "RTSTiledMap.h"


PathFinder::PathFinder()
{
	isSearchingPath = false;
}

void PathFinder::update()
{

}

// todos los pasos
void PathFinder::run(const Vector2I& start, const Vector2I& target, const Vector2I, RTSTiledMap* _tiledMap, const SEARCHING_TYPE _searchTypeID)
{	
	if (isSearchingPath == false)
	{
		// cambiarle el nombre
		bool sizeX = ((start.x >= 0) && (start.x < _tiledMap->getMapSize().x) && (start.y >= 0) && (start.y < _tiledMap->getMapSize().y));
		bool sizeY = ((target.x >= 0) && (target.x < _tiledMap->getMapSize().x) && (start.y >= 0) && (target.y < _tiledMap->getMapSize().y));

		if (_tiledMap == nullptr || _searchTypeID == SEARCHING_TYPE::NONE || sizeX == false || sizeY == false || start == target) {
			return;
		}

		currentNode.position = start;
		targetNode.position = target;
		isSearchingPath = true;

	}
	else
	{
		step(_tiledMap, _searchTypeID);
	}
}

// Solo un paso
// Search for the next step 
bool PathFinder::step(RTSTiledMap* _tiledMap, const SEARCHING_TYPE _searchTypeID)
{
	switch (_searchTypeID)
	{
	case SEARCHING_TYPE::BF:
		BreadthFirstSearch(_tiledMap);
		break;
	case SEARCHING_TYPE::DF:

		break;
	case SEARCHING_TYPE::BEST:

		break;
	case SEARCHING_TYPE::DIJKSTRA:

		break;
	case SEARCHING_TYPE::ASTAR:

		break;
	}
		
}

void PathFinder::BreadthFirstSearch(RTSTiledMap* _tiledMap)
{




	_tiledMap->getType(currentNode.x , currentNode.y);

}

