h, w = map(int, input().split())
a = [input() for i in range(h)]

while "." * w in a:
  a.remove("." * w)
hh = len(a)
  
a = ["".join(h_line) for h_line in zip(*a)]
while "." * hh in a:
  a.remove("." * hh)
    
for line in zip(*a):
  print("".join(line))