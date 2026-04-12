

def I(): return int(input())
def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

def main():
    mod=10**9+7
    c=input()
    L=["a","i","u","e","o"]
    f=0
    for i in range(5):
        if c==L[i]:
            f=1
            
    if f==1:
        print("vowel")
    else:
        print("consonant")

main()
