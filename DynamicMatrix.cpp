#include "DynamicMatrix.h"

DynamicMatrix::DynamicMatrix(int rows, int cols)
  : m_rows(rows),
    m_cols(cols)
{ 
	try
	{
		m_matrix = new int * [m_rows];
		for (int i = 0; i < m_rows; ++i)
		{
			m_matrix[i] = NULL;
			try
			{
				m_matrix[i] = new int [m_cols];
			}catch(const std::bad_alloc & ex)
			{
				for (; i >= 0; --i)
					delete [] m_matrix[i];
				throw;
			}
		}

	}catch(const std::bad_alloc & ex)
	{
		delete [] m_matrix;
	}
	
	for (int i = 0; i < m_rows; ++i)
	{
		for (int j = 0; j < m_cols; ++j)
		{
			m_matrix[i][j] = (i * m_cols) + j;
		}
	}
}

DynamicMatrix::~DynamicMatrix()
{
	
	for (int i = 0; i < m_rows; ++i)
		delete [] m_matrix[i];
	
	delete [] m_matrix;
}

std::ostream & operator<<(std::ostream & os, const DynamicMatrix & dm){ 
  for (int j=0; j<dm.m_rows; ++j){	
    for (int i=0; i<dm.m_cols; ++i){
      os << dm.m_matrix[j][i] << " ";  
    }
    os << std::endl;
  }
  return os; 
}

