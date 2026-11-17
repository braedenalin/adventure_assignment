Reflection Questions
1. The TODOs have a range of time complexities from O(1) to O(n^2).
2. Each scene only uses exactly the amount of choices because using Scene<T>*choices[3] makes you have
more than you need. Additionally, an ending will have 0 children, which means there is no point in requiring 3.
3. The destructor deletes these in order: data_, every child scene (which will automatically delete its descendents, and
the choices array. Order matters because the choices array contains all the pointers that are needed to find the children.
If I deleted the choices array first, then I would be unable to find them, and the children would leak from the memory.
4. The greedy path was 2-1-3-1-2-1, where it ended up with 37 loot, but died. The optimal path was 2-1-3-1-1-1, where it
ended with only 17 loot, but you win. Greedy lost because there was an opportunity to gain lots of loot (killing small animals
while you were too tired to do anything with it after), and because greedy was out in the open with raw meat and had to sleep,
a tiger was able to smell you, and you had no way to defend yourself, which is why greedy died.
5. bestLoot has a time complexity of only O(n) because each node only has 1 parent, and it only checks a scene and its
   children. It doesn't recompute the same scene between parents because scenes arent shared from paths.
6. My game uses search() to check whether a player has an item, addFront() to add a newly collected item,
size() to print the number of items in your inventory, print() to display the inventory, and deleteFront() in the list 
destructor. One call to search() takes O(n) (n being number of items) because it might have to inspect everything in
the linked list.