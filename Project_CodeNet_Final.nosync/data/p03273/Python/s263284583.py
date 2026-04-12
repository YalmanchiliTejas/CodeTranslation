import numpy as np

inputs = raw_input().replace("\n", "")
H, W = map(int, inputs.split(" "))

lines = np.asarray([list(raw_input().replace("\n", "")) for h in xrange(H)])

h_indexs, w_indexs = map(set, np.where(lines == "#"))

outlines = lines[list(h_indexs), :][:, list(w_indexs)]
for outline in outlines:
    print "".join(outline)