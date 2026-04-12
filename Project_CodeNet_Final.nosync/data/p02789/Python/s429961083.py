import queue
import copy
import math
from collections import deque

# そのまま入力文字列の入力
n, m = map(int, input().split())

print("Yes" if n == m else "No")