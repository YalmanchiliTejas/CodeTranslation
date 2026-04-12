def inint(): return int(input())
def inlint(): return list(map(int, input().split()))
def infloat(): return float(input())
def inlffloat(): return list(map(float, input().split()))
def inl(): return list(input())
def putlint(): return "".join(list(map(str, ans)))

a = input()

if(a=="a" or a=="i" or a=="u" or a=="e" or a=="o"):
    print("vowel")
else:
    print("consonant")