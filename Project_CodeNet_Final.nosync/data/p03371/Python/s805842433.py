A,B,C,X,Y=map(int,input().split())

#すべて単品, min(X,Y)をABで賄い不足を単品, すべてAB(超過は問題ない)
total=[0,0,0]
#case1
total[0]=A*X+B*Y
#case2
if X>=Y:
    cost=A
else:
    cost=B
total[1]=min(X,Y)*2*C+(max(X,Y)-min(X,Y))*cost
#case3
total[2]=max(X,Y)*2*C

print(min(total))
