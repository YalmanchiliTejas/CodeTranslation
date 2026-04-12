def ri(): return int(input())
def rli(): return list(map(int, input().split()))
def ris(): return list(input())
def pli(): return "".join(list(map(str, ans)))

a = input()
v = "a e i o u".split()
if(a in v):
    print("vowel")
else:
    print("consonant")
