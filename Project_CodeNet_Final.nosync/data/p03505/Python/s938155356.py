K, A, B = map(int, input().split())
if A >= K:
    print("1")
    exit()

if B >= A:
    print("-1")
    exit()

ans = ((K - A - 1) // (A - B) + 1) * 2 + 1
print(ans)
