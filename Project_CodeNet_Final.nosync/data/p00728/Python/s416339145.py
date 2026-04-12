N = int(input())
while N != 0:
        total = 0
        minimam = 1000
        maximam = 0
        for _ in range(N):
                s = int(input())
                total += s
                minimam = min(minimam, s)
                maximam = max(maximam, s)
        print(int((total-minimam-maximam)/(N-2)))
        N = int(input())
