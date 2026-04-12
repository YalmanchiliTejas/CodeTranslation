# coding: utf-8
# Your code here!

N = int(input())
X = list(map(int, input().rstrip().split(' ')))

v = 1
for i in range(1, N):
    if X[i] >= max(X[:i]):
        v += 1
        
print(v)