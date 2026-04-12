h,w=map(int,input().split())
s=[input()for _ in[0]*h]
a=[['..','..'],['.#','..'],['..','#.'],['##','..'],['..','##'],['#.','#.'],['.#','.#'],['##','.#'],['#.','##']]
for i in range(h-1):
  for j in range(w-1):
    t=s[i][j:j+2]
    u=s[i+1][j:j+2]
    for b in a:
      if t==b[0]and u==b[1]:
        break
    else:
      print('Impossible')
      exit()
print('Possible')