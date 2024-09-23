#ifndef TYPES_HPP
#define TYPES_HPP
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <utility>
#include <memory>


using namespace std;

namespace ariel{
    class valid_resources : public exception {
    private:
        const char * message;

    public:
        valid_resources(const char *msg) : message(msg) {}
        const char* what() const noexcept override {
            return message;
        }
    };
    // enum of all resource types
    enum Color {
        Black = 30,
        Red = 31,
        Green = 32,
        Blue = 34
    };
    enum ResourceType {
        Ore = 1,
        Wheat = 2,
        Sheep = 3,
        Wood = 4,
        Brick = 5,
        Desert = 7      // not a resoure - tile type
    };

    string getResourceName(ResourceType resource);

    enum VertexPosition {
        VERTEX_TOP_LEFT = 0,
        VERTEX_TOP = 1,
        VERTEX_TOP_RIGHT = 2,
        VERTEX_BOTTOM_RIGHT = 3,
        VERTEX_BOTTOM = 4,
        VERTEX_BOTTOM_LEFT = 5,
        NUM_OF_VERTICES = 6
    };

    enum EdgePosition {
        EDGE_TOP_LEFT = 0,
        EDGE_TOP_RIGHT = 1,
        EDGE_RIGHT = 2,
        EDGE_BOTTOM_RIGHT = 3,
        EDGE_BOTTOM_LEFT = 4,
        EDGE_LEFT = 5,
        NUM_OF_EDGES = 6
    };

    enum BuildableTypes{
        None = 0,
        Road = 1,
        Settlement = 2,
        City = 3
    };

    // edgePosition + - operators override
    inline EdgePosition operator+(EdgePosition pos, int num){
        return (EdgePosition)((((int)pos + num)) % (int)NUM_OF_EDGES);
    }
    inline EdgePosition operator+(int num, EdgePosition pos){
        return (EdgePosition)((((int)pos + num)) % (int)NUM_OF_EDGES);
    }
    inline EdgePosition operator-(EdgePosition pos, int num){
        int result = ((((int)pos - num)) % (int)NUM_OF_EDGES);
        if (result < 0){
            result += (int)NUM_OF_EDGES;
        }
        return (EdgePosition)result;
    }
    inline EdgePosition operator-(int num, EdgePosition pos){
        int result = (((num - (int)pos)) % (int)NUM_OF_EDGES);
        if (result < 0){
            result += (int)NUM_OF_EDGES;
        }
        return (EdgePosition)result;
    }
    inline VertexPosition operator+(VertexPosition pos, int num){
        return (VertexPosition)((((int)pos + num)) % (int)NUM_OF_VERTICES);
    }
    inline VertexPosition operator+(int num, VertexPosition pos){
        return (VertexPosition)((((int)pos + num)) % (int)NUM_OF_VERTICES);
    }
    inline VertexPosition operator-(VertexPosition pos, int num){
        int result = ((((int)pos - num)) % (int)NUM_OF_VERTICES);
        if (result < 0){
            result += (int)NUM_OF_VERTICES;
        }
        return (VertexPosition)result;
    }
    inline VertexPosition operator-(int num, VertexPosition pos){
        int result = (((num - (int)pos)) % (int)NUM_OF_VERTICES);
        if (result < 0){
            result += (int)NUM_OF_VERTICES;
        }
        return (VertexPosition)result;
    }

}
#endif      // TYPES_HPP