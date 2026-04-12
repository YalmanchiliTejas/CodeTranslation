def checkm(n,mount):
    max = 0
    ans = 0
    for i in mount:
        if max <= i:
            max = i
            ans += 1
    return ans

n = int(input())
mount = input().split()
mount = [int(i) for i in mount]

print(checkm(n,mount))
