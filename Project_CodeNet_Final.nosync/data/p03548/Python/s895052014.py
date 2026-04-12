#https://atcoder.jp/contests/abc078/tasks/abc078_b
X,Y,Z = map(int,input().split())
X = X - Z
Y = Y + Z
print(X//Y)



