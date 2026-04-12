def ri(): return int(input())
def rli(): return list(map(int, input().split()))
def rls(): return list(input())
def pli(a): return "".join(list(map(str, a)))
def plis(a): return " ".join(list(map(str, a)))

S = input()
flag = False
for i in range(len(S)-1):
    if(S[i]+S[i+1] == "AC"): flag = True

if(flag): print("Yes")
else: print("No")