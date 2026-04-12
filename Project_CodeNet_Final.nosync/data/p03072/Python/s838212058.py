N = int(input())
H = list(map(int,input().split()))
maxH = 0
n = 1

for i, h in enumerate(H):
  if i == 0:
  	maxH = h
  else:
    if h >= maxH:
    	n += 1
    	maxH = h
    
print(n)