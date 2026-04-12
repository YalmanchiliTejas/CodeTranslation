H, W = tuple(int(i) for i in input().split())
As = [input() for i in range(H)]

a = [i for i in As if "#" in i]
b = ["".join(j[i] for j in a) for i in range(W)]
b_ = [i for i in b if "#" in i]
a_ = ["".join(j[i] for j in b_) for i in range(len(b_[0]))]

for i in a_:
  print(i)
