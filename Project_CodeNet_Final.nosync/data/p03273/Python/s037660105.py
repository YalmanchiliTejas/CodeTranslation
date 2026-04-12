class Solver(object):
    def __init__(self):
        self.h, self.w = list(map(int, input().split(" ")))
        self.grid = [[] for _ in range(self.h)]  # grid[row][column]
        for row in range(self.h):
            for value in input():
                self.grid[row].append(value)

    def solve(self):
        for row in range(self.h):
            for column in range(self.w):
                if self.grid[row][column] == ".":
                    self.check_and_delete(row, column)
        self.print_grid()

    def check_and_delete(self, row, column):
        # row-wise
        delete = True
        for c in range(self.w):
            if self.grid[row][c] is not None:
                if self.grid[row][c] == "#":
                    delete = False
        if delete:
            for c in range(self.w):
                self.grid[row][c] = None

        # column-wise
        delete = True
        for r in range(self.h):
            if self.grid[r][column] is not None:
                if self.grid[r][column] == "#":
                    delete = False
        if delete:
            for r in range(self.h):
                self.grid[r][column] = None
    
    def print_grid(self):
        for row in self.grid:
            printed = False
            for column in row:
                if column is not None:
                    printed = True
                    print(column, end="")
            if printed:
                print()


if __name__ == "__main__":
    s = Solver()
    s.solve()