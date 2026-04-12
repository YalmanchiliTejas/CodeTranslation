def stack(layer, length):
  if layer==1:
    return "BPPPB"[:length].count("P")
  else:
    if length==(lengths[layer-1]+1)/2:
      return ps[layer-2]+1
    elif length<(lengths[layer-1]+1)/2:
      return stack(layer-1, length-1)
    else:
      return ps[layer-2]+1+stack(layer-1, length-lengths[layer-2]-2)
    
inp = input().split()
layer = int(inp[0])
length = int(inp[1])
lengths = [5]
ps = [3]
for i in range(49):
  lengths.append(lengths[i]*2+3)
  ps.append(ps[i]*2+1)
print(stack(layer, length))