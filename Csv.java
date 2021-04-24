import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class Csv{

	public static void main(String[] args) {
		
		String read_csv_File = "C:/persons.csv"; //PATH OF THE CSV FILE.

		Person obj = new Person();
		obj.read(read_csv_File);
	}

}

class Person{

	 static final String delimiter = ",";

	 static void read(String read_csv_File) {

		try {
			File file = new File(read_csv_File);

			FileReader fr = new FileReader(file);
			BufferedReader br = new BufferedReader(fr);


			String line = "";
			String[] resultArr;


			while ((line = br.readLine()) != null) {

				resultArr = line.split(delimiter);

				
				for (String str : resultArr) {
					System.out.print(str + " ");
				}
				System.out.println();

			}
			br.close();

		}
		
		 catch (IOException ex) {
			ex.printStackTrace();
		}

	}
} 