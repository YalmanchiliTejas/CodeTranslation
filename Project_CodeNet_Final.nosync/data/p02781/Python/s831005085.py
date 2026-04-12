class S:
    def solve(self, n, k):
        self.n = n
        return self.dfs(0, k, False)
    def dfs(self, x, y, free=False):
        if y == 0:
            return 1
        if x >= len(self.n):
            return 0
        if free:
            return 9 * self.dfs(x + 1, y - 1, free) + self.dfs(x + 1, y, free)
        else:
            t = int(self.n[x])
            r = 0
            if t > 0:
                r += 1 * self.dfs(x + 1, y - 1, False)
                r += (t - 1) * self.dfs(x + 1, y - 1, True)
            r += self.dfs(x + 1, y, t > 0)
            return r


n = raw_input()
k = input()
print S().solve(n, k)
