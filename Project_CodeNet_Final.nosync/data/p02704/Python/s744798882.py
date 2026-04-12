#!/usr/bin/python3
import math

def f():
    print(-1)
    exit()

def gen(p, n, s, t, u, v, result):
    a = [ [ -1 for i in range(n) ] for j in range(n) ]
    for i in range(n):
        ub = (u[i] >> p) & 1
        vb = (v[i] >> p) & 1
        if s[i] == 0:
            if ub == 1:
                a[i] = [ 1 for j in range(n) ]
        else:
            if ub == 0:
                a[i] = [ 0 for j in range(n) ]
            
        if t[i] == 0:
            if vb == 1:
                for j in range(n):
                    if a[j][i] == 0:
                        f()
                    a[j][i] = 1
        else:
            if vb == 0:
                for j in range(n):
                    if a[j][i] == 1:
                        f()
                    a[j][i] = 0

    for i in range(n):
        ub = (u[i] >> p) & 1
        if s[i] == 1 and ub == 1:
            if 1 in a[i]:
                continue
            
            for j in range(n):
                vb = (v[j] >> p) & 1
                if t[j] == 1 and vb == 1:
                    a[i][j] = 1
                    break

                if t[j] == 0 and vb == 0:
                    if [ a[k][j] for k in range(n) ].count(1) < n - 1:
                        a[i][j] = 1
                        break;
            else:
                f()

    for i in range(n):
        ub = (u[i] >> p) & 1
        if s[i] == 0 and ub == 0:
            if a[i].count(1) == n:
                f()
                
    for j in range(n):
        vb = (v[j] >> p) & 1
        if t[j] == 1 and vb == 1:
            if 1 in [ a[k][j] for k in range(n) ]:
                continue

            for i in range(n):
                ub = (u[i] >> p) & 1
                if s[i] == 1 and ub == 1:
                    a[i][j] = 1
                    break

                if s[i] == 0 and ub == 0:
                    if a[i].count(1) < n - 1:
                        a[i][j] = 1
                        break
            else:
                f()

    for j in range(n):
        vb = (v[j] >> p) & 1
        if t[j] == 0 and vb == 0:
            if [ a[k][j] for k in range(n) ].count(1) == n:
                fi()
                
    for i in range(n):
        for j in range(n):
            v = a[i][j] if a[i][j] >= 0 else 0
            result[i][j] = result[i][j] | (v << p)

n = int(input())
s = tuple(map(int, input().split()))
t = tuple(map(int, input().split()))
u = tuple(map(int, input().split()))
v = tuple(map(int, input().split()))

p = math.log2(max(u + v))

if p.is_integer():
    p = int(p) + 1
else:
    p = int(math.ceil(p))
    
result = [ [ 0 for i in range(n) ] for j in range(n) ]


for i in range(p):
    gen(i, n, s, t, u, v, result)

for i in range(n):
    print(' '.join(map(str, result[i])))
