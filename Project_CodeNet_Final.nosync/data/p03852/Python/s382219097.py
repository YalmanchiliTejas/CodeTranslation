#k = int(input())
#s = input()
#a, b = map(int, input().split())
#s, t = map(str, input().split())
#l = list(map(int, input().split()))
#l = [list(map(int,input().split())) for i in range(n)]

s = input()

ans = "consonant"

if s == "a" or s == "e" or s == "i" or s =="o" or s=="u":
    ans = "vowel"
print(ans)
