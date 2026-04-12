N = int(input())
n = input().rstrip().split(' ')
H = [int(i) for i in n]
c = 1
s = [0]*N
s[0] = H[0]
for i in range(1,N):
  if max(s)<= H[i] :
    c +=1
    s[i] = H[i]
  else:
    pass
print(c)
    
    