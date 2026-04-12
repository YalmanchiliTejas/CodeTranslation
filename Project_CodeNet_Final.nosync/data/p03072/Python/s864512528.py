def mi(): return map(int,input().split())
def lmi(): return list(map(int,input().split()))
def ii(): return int(input())
def isp(): return input().split()
 
n=ii()
h=lmi()
cnt=1
max_h=0
for i in range(n-1):
  max_h=max(max_h,h[i])
  if h[i]<=h[i+1] and h[i+1]>=max_h:
    cnt+=1
    
print(cnt)
