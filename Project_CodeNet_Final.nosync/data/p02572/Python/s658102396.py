n = int(input())
a = list(map(int,input().split()))
len_a = n
sum_list = sum(a)-a[0]
count = 0
for j,i in enumerate(a):
  if j != len_a -1:
    count += i*sum_list
    sum_list -= a[j+1]
    
print(count%1000000007)