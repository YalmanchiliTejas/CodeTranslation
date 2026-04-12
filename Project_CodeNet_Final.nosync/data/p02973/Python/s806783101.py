from bisect import bisect
n = int(input())
a = [int(input()) for _ in range(n)]
update_list=[11 for _ in range(n+1)]
for old_element in range(n):
    update_position=bisect(update_list,-a[old_element])
    update_list[update_position]=-a[old_element]

ans=0
while update_list[ans] <= 0:
	ans += 1
print(ans)