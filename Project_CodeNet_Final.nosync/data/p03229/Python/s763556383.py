from sys import stdin
n = int(stdin.readline().rstrip())
li = [int(stdin.readline().rstrip()) for _ in range(n)]
li.sort()
if n%2 == 1:
    mid = li[n//2]
    mae = li[:n//2]
    ushiro = li[n//2+1:]
    sono1 = -mid - mae[-1]
    sono1 += sum(ushiro)*2-sum(mae[:-1])*2
    sono2 = mid + ushiro[0]
    sono2 += sum(ushiro[1:])*2-sum(mae)*2
    print(max(sono1,sono2))
else:
    mae = li[:n//2]
    ushiro = li[n//2:]
    sono3 = -mae[-1] + ushiro[0]
    sono3 += sum(ushiro[1:])*2-sum(mae[:-1])*2
    print(sono3)