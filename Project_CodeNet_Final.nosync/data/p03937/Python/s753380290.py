# coding: utf-8
import sys
input = sys.stdin.readline

H, W = map(int, input().split())
route = ""
for _ in range(H):
    route += input()

print("Possible" if route.count("#")==(H+W-1) else "Impossible")