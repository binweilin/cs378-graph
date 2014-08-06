// ----------------------
// projects/graph/Graph.h
// Copyright (C) 2014
// Glenn P. Downing
// ----------------------

#ifndef Graph_h
#define Graph_h

// --------
// includes
// --------

#include <cassert> // assert
#include <cstddef> // size_t
#include <utility> // make_pair, pair
#include <vector>  // vector
#include <iterator>
#include <stack>   // stack
#include <set>
using namespace std;
// -----
// Graph
// -----

class Graph {
    public:
        // --------
        // typedefs
        // --------

        typedef int vertex_descriptor;
        typedef std::pair <vertex_descriptor, vertex_descriptor> edge_descriptor;
    
        typedef std::vector<vertex_descriptor>::const_iterator vertex_iterator;
        typedef std::set<edge_descriptor>::iterator edge_iterator;
        typedef std::vector<vertex_descriptor>::const_iterator adjacency_iterator;

        typedef std::size_t vertices_size_type;
        typedef std::size_t edges_size_type;

    public:
        // --------
        // add_edge
        // --------

        /**
         * @param v1 a vertex_descriptor
         * @param v2 a vertex_descriptor
         * @return a pair <edge_descriptor, bool>
         */
        friend std::pair<edge_descriptor, bool> add_edge (vertex_descriptor v1, vertex_descriptor v2, Graph& g) {
            int i = max(v1, v2);
            if(find(g.vertices.begin(), g.vertices.end(), i) == g.vertices.end()){
                int s = g.vertices.size();
                while(i != s-1){
                    add_vertex(g);
                    i--;
                }
            }
            edge_descriptor e = make_pair(v1, v2);
            bool b = g.edges.insert(e).second;
            if(b)
                g.g[v1].push_back(v2);
            std::sort(g.g[v1].begin(), g.g[v1].end());
            return std::make_pair(e, b);
        }

        // ----------
        // add_vertex
        // ----------

        /**
         * @param g the graph where vertex_descriptor is added
         * @return the vertex_descriptor added
         */
        friend vertex_descriptor add_vertex (Graph& g) {
            // <your code>
            vertex_descriptor v = g.vertices.size(); // fix
            g.vertices.push_back(v);
            vector<vertex_descriptor> v2;
            g.g.push_back(v2);
            return v;}

        // -----------------
        // adjacent_vertices
        // -----------------

        /**
         * adjacent_vertices function
         * @param v a vertex_descriptor
         * @param g the graph where the vertex_descriptor is
         * @return a pair <adjacency_iterator, adjacency_iterator>
         */
        friend std::pair<adjacency_iterator, adjacency_iterator> adjacent_vertices (vertex_descriptor v, const Graph& g) {
            // <your code>
            adjacency_iterator b = g.g[v].begin();
            adjacency_iterator e = g.g[v].end();
            return std::make_pair(b, e);}

        // ----
        // edge
        // ----

        /**
         * @param v1 a vertex_descriptor
         * @param v2 a vertex_descriptor
         * @param g the graph where the vertex_descriptor is
         * @return a pair <edge_descriptor, bool>
         */
        friend std::pair<edge_descriptor, bool> edge (vertex_descriptor v1, vertex_descriptor v2, const Graph& g) {
            // <your code>
            edge_descriptor e = make_pair(v1, v2);
            bool            b  = (g.edges.find(e) != g.edges.end());
            return std::make_pair(e, b);}

        // -----
        // edges
        // -----

        /**
         * @param g a Graph
         * @return a pair <edge_iterator, edge_iterator>
         */
        friend std::pair<edge_iterator, edge_iterator> edges (const Graph& g) {
            // <your code>
            edge_iterator b = g.edges.begin();
            edge_iterator e = g.edges.end();
            return std::make_pair(b, e);}

        // ---------
        // num_edges
        // ---------

        /**
         * @param g a Graph
         * @return the number of edges in the given graph
         */
        friend edges_size_type num_edges (const Graph& g) {
            // <your code>
            edges_size_type s = g.edges.size(); // fix
            return s;}

        // ------------
        // num_vertices
        // ------------

        /**
         * @param g a Graph
         * @return the number of vertices in the given graph
         */
        friend vertices_size_type num_vertices (const Graph& g) {
            // <your code>
            vertices_size_type s = g.vertices.size(); // fix
            return s;}

        // ------
        // source
        // ------

        /**
         * @param r an edge_descriptor
         * @param g a Graph
         * @return the source vertex_descriptor 
         */
        friend vertex_descriptor source (edge_descriptor e, const Graph& g) {
            // <your code>
            vertex_descriptor v = e.first; // fix
            return v;}

        // ------
        // target
        // ------

        /**
         * @param e an edge_descriptor
         * @param g a Graph
         * @return the target vertex_descriptor
         */
        friend vertex_descriptor target (edge_descriptor e, const Graph& g) {
            // <your code>
            vertex_descriptor v = e.second; // fix
            return v;}

        // ------
        // vertex
        // ------

        /**
         * @param n index of the vertex
         * @param g a Graph
         * @return the nth vertex_descriptor of the graph
         */
        friend vertex_descriptor vertex (vertices_size_type n, const Graph& g) {
            // <your code>
            // Graph gr = g;
            // if(find(gr.vertices.begin(), gr.vertices.end(), n) == gr.vertices.end()){
            //     int i = 0;
            //     while(i != n + 1){
            //         add_vertex(gr);
            //         i++;
            //     }
            // }

            vertex_descriptor vd = n; // fix
            return vd;}

        // --------
        // vertices
        // --------

        /**
         * @param g a Graph
         * @return the nth vertex_descriptor of the graph
         */
        friend std::pair<vertex_iterator, vertex_iterator> vertices (const Graph& g) {
            // <your code>
            vertex_iterator b = g.vertices.begin();
            vertex_iterator e = g.vertices.end();
            return std::make_pair(b, e);}

    private:
        // ----
        // data
        // ----

        std::vector< std::vector<vertex_descriptor> > g; // something like this
        std::vector<vertex_descriptor> vertices;
        std::set<edge_descriptor> edges;

        // -----
        // valid
        // -----

        /**
         * valid function
         */
        bool valid () const {
            // <your code>
            //return (vertices.size() == 0 && edges.size() == 0 && g.size() == 0);
            return true;
        }

    public:
        // ------------
        // constructors
        // ------------

        /**
         * default constructor
         */
        Graph (){
            // <your code>
            assert(valid());}

        // Default copy, destructor, and copy assignment
        // Graph  (const Graph<T>&);
        // ~Graph ();
        // Graph& operator = (const Graph&);
    };

#endif // Graph_h
