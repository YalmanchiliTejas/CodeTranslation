A,B,C,X,Y = map(int,input().split())

ans = 0
judge = 0 #X < Y: 0,X >= Y: 1
if(X < Y):
  judge = 0
else:
  judge = 1
  
#A,B それぞれ一枚買うとき //「Aセット」+「Bセット」//と//「Cセット」*2//
#の安いほうをたくさん買う
if((A+B) > C*2 ):
  if(judge == 0):#X < Y 
   ans += C*2*X
   #残りはBをY-X枚買う
   if( B < 2*C):
    ans += B*(Y-X) 
   else:
    ans += C*2*(Y-X)    
  elif(judge == 1):#Y <= X
   ans += C*2*Y 
   #残りはAをX-Y枚買う
   if( A < 2*C):
    ans += A*(X-Y) 
   else:
    ans += C*2*(X-Y)

else:
  if(judge == 0):#X < Y 
   ans += (A+B)*X
   #残りはBをY-X枚買う
   if( B < 2*C):
    ans += B*(Y-X) 
   else:
    ans += C*2*(Y-X)    
  elif(judge == 1):#Y <= X
   ans += (A+B)*Y 
   #残りはAをX-Y枚買う
   if( A < 2*C):
    ans += A*(X-Y) 
   else:
    ans += C*2*(X-Y)

print(ans)
  
  