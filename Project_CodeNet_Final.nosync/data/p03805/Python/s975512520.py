#!/usr/bin/env python3
# -*- coding: utf-8 -*-

class Graph():

    def __init__(self):
        self.adjacency_dict = {}
    
    def add_vertex(self, v):
        self.adjacency_dict[v] = []

    def add_edge(self, v1, v2):
        self.adjacency_dict[v1].append(v2)
        self.adjacency_dict[v2].append(v1)

    def remove_edge(self, v1, v2):
        self.adjacency_dict[v1].remove(v2)
        self.adjacency_dict[v2].remove(v1)

    def remove_vertex(self,v):
        while self.adjacency_dict[v] != []:
            adjacency_vertex = self.adjacency_dict[v][-1]
            self.remove_edge(v, adjacency_vertex)
        del adjacency_vertex[v]

    def get_vertexes(self):
        return self.adjacency_dict.keys()

    def get_edges(self, v):
        return self.adjacency_dict[v]

    def print_graph(self):
        print(self.adjacency_dict)

import itertools

g = Graph()
N, M = map(int, input().strip().split())
for i in range(N):
    g.add_vertex(i+1)
for _ in range(M):
    a, b = map(int, input().strip().split())
    g.add_edge(a, b)
res = 0
permutations_vertexes = itertools.permutations(g.get_vertexes())
for permutation in permutations_vertexes:
    prev_vertex = permutation[0]
    if prev_vertex != 1:
        continue
    can_all_vertex = True
    for vertex in permutation:
        if prev_vertex == vertex:
            continue
        if vertex not in g.get_edges(prev_vertex):
            can_all_vertex = False
            break
        prev_vertex = vertex
    if can_all_vertex:
        res += 1
print(res)
