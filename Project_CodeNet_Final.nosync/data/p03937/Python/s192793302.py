import sys
H,W=map(int,input().split())
listA=[list(input()) for i in range(H)]
start=[0,0]
while 1:  
  if start[0]!=H-1 and start[1]!=W-1 and listA[start[0]+1][start[1]]=="#" and listA[start[0]][start[1]+1]=="#":
    print("Impossible")
    sys.exit()
  if start[0]!=0 and start[1]!=0 and listA[start[0]-1][start[1]]=="#" and listA[start[0]][start[1]-1]=="#":
    print("Impossible")
    sys.exit()
  if start==[H-1,W-1]:
    print("Possible")
    sys.exit()  
  if start[0]!=H-1 and listA[start[0]+1][start[1]]=="#":
    start=[start[0]+1,start[1]]
    continue  
  if start[1]!=W-1 and listA[start[0]][start[1]+1]=="#":
    start=[start[0],start[1]+1]    
  else:
    print("Impossible")