n,x,m = map(int,input().split())
k_1 = set()
k_2 = set()
tmp = list()
loop_number = 0
loop_sum = 0
while x not in k_1:
	k_1.add(x)
	x = x*x%m
while x not in k_2:
	k_2.add(x)
	tmp.append(x)
	loop_number+=1
	loop_sum+=x 
	x = x*x%m
ans = 0
k_1 = list(k_1)
for i in range(len(k_1)):
	ans +=  k_1[i]
ans = ans + loop_sum * ((n-len(k_1))//loop_number)
for i in range((n-len(k_1))%loop_number):
	ans += tmp[i]
print(ans)