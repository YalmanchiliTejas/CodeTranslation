import sys

def f1(s): return "".join([d0[c] for c in s])

d0={"M":"10010","N":"10011"}
a="ABCD";
for i in range(4): d0[a[i]]=format(i,"02b")
a="EFGHIJKL"
for i in range(8): d0[a[i]]=format(i,"03b")
L0="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
L1=" ',-.?"+L0
L2=L0+" .,-'?"

dc={}
a="J,EE,EH,MF,GF,EF,IJ,NG,BB,AB,K,BF,NH,GE,BD,NE,BC,"\
  "AI,NF,NK,AJ,L,NL,CA,AK,AL,NI,NJ,EG,MG,MH,ME".split(",")
for i,e in enumerate(a): dc[f1(e)]=L1[i]
ec={}
for i in range(32): ec[L2[i]]=format(i,"05b")
for s0 in sys.stdin:
  s1="".join([ec[c] for c in s0.strip("\n")])
  s=""
  x=""
  for c in s1:
    s+=c
    if s in dc: x+=dc[s]; s=""
  print x