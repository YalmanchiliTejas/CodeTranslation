import sys
N,T,E=map(int,raw_input().split())
X=map(int,raw_input().split())
for i in range(N):
    for t in range(1,1441):
        if T-E<=X[i]*t<=T+E:
            print i+1
            sys.exit()
print -1