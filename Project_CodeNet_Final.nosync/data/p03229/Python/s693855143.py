n = int(input())
alst = [int(input()) for _ in range(n)]
alst.sort()
if n % 2 == 0:
    mid = n // 2
    ans = sum(alst[mid + 1:]) * 2 + alst[mid] - sum(alst[:mid - 1]) * 2 - alst[mid - 1]
else:
    mid = n // 2
    ans1 = sum(alst[mid + 1:]) * 2 - sum(alst[:mid - 1]) * 2 - alst[mid - 1] - alst[mid]
    ans2 = sum(alst[mid + 2:]) * 2 - sum(alst[:mid]) * 2 + alst[mid + 1] + alst[mid]
    ans = max(ans1, ans2)
    
print(ans)