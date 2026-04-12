N=int(input())
temp=list(map(int,input().split()))
temp_s=sorted(temp)
min_median=temp_s[N//2-1]
max_median=temp_s[N//2]
if max_median==min_median:
   for i in range(N):
      print(max_median)
   exit()
for i in temp:
   if i <= min_median:
      print(max_median)
   else:
      print(min_median)