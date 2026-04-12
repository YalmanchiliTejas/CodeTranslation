n = int(input())
lst = list(map(int, input().split()))
s = (sum(lst)**2 - sum([z**2 for z in lst]))//2
print(s % (pow(10,9)+7))