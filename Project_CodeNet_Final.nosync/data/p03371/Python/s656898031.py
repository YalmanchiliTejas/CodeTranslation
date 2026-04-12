a,b,c,x,y = map(int,input().split())
c = 2*c
List = []
for i in range(10**5+1):
  m = i*c + max(0,a*(x-i)) + max(0,b*(y-i))
  List.append(m)
print(min(List))