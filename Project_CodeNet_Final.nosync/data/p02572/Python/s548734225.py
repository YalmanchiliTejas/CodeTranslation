n = int(input())
li_a = list(map(int, input().split()))
answer = 0
su = sum(li_a)
mo = (10 ** 9) + 7
for idx, a in enumerate(li_a):
    su = su - a
    answer += (a * su)
print(answer % mo)