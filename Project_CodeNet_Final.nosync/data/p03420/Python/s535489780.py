import sys
n,k = map(int,input().split())
#if k == 0:
#    print(n**2)
 #   sys.exit
count = 0
for i in range(1,n+1):
    tmp_count = max(0,i - k)
    #print(i,n // i,tmp_count,(n // i)* tmp_count + max(0,(n % k)-k+1),max(0,(n % i)-k+1),n % i)
    count += (n // i)* tmp_count + max(0,(n % i)-k+1)

if k == 0:
  count -= n
print(count)