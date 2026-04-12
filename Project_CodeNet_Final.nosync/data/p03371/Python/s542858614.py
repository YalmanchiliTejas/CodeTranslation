a,b,c,x,y=map(int,input().split())
#A,Bをそれぞれ買う
cand1=a*x+b*y
#すべてABピザでそろえる
cand2=2*c*max(x,y)
#A,Bのうち必要枚数が少ないほうをすべてABピザで作る
cand3=2*c*x+b*(y-x) if x<y else 2*c*y+a*(x-y)
print(min(cand1,cand2,cand3))