N = input().split()
print(["YES", "NO"][not(int("".join(N))%4==0)])