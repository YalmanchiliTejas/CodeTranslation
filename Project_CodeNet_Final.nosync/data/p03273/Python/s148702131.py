import sys
input = sys.stdin.readline
#n = int(input())
#l = list(map(int, input().split()))
'''
A=[]
B=[]
for i in range():
    a, b = map(int, input().split())
    A.append(a)
    B.append(b)'''

h,w=map(int, input().split())
m = [list(input().rstrip()) for i in range(h)]
ok_w=[True for i in range(h)]
ok_h=[True for i in range(w)]
#print(m)
for i in range(h):
    for j in range(w):
        #print(m[i][j])
        if "#" == m[i][j]:
           ok_w[i]=False
           ok_h[j]=False
#print(ok_h,ok_w)
for i in range(h):
    for j in range(w):
        if not ok_w[i] and not ok_h[j]:
            print(m[i][j],end="")
    print("\n",end="")