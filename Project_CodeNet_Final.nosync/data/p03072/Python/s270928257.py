N = input();
l = map(int, raw_input().split());
ans = 1;

for i in range(1,N):
	if (max(l[0:i]) <= l[i]):
		ans += 1;
print ans;