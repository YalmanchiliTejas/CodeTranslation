li = list(map(int,input().split()))
total = 100*li[0] + 10*li[1]+li[2]
print("YES" if total % 4 == 0 else "NO")