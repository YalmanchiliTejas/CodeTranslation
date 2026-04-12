N = int(input())
a = [0]*N
result = []
for i in range(N):
 a[i] = int(input())
a = sorted(a)
if N%2 != 0:
 a_sub = sorted(a,key=lambda x: -x)
 a_0 =a[N//2]
 for j in range(N//2):
  if j %2 ==0:
   result.insert(0,a_sub[j])
   result.append(a[j])
  else:
   result.insert(0,a[j])
   result.append(a_sub[j])
 tmp1 = abs(result[0] - a_0)
 tmp2 = abs(result[N-2] -a_0)
 if tmp1 < tmp2:
  result.append(a_0)  
 else:
  result.insert(0,a_0)
else:
 a_sub = sorted(a,key=lambda x: -x)
 for j in range(N//2):
  if j %2 ==0:
   result.insert(0,a_sub[j])
   result.append(a[j])
  else:
   result.insert(0,a[j])
   result.append(a_sub[j])
result_sum = 0
for k in range(N-1):
 result_sum = result_sum + abs(result[k] - result[k+1])
print(result_sum)