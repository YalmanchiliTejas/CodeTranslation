n = int(input())
a_list = list(map(int, input().split()))

s_2 = 0
for i in a_list:
    s_2 += i**2

ans = (sum(a_list)**2 - s_2)//2  

ans = ans%(10**9+7)
print(ans)